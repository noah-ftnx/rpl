#include <cassert>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <unistd.h> // open, read
using namespace std;

// path -> checksum
using FileChecksum = unordered_map<string, string>;
// checksum -> chunk_id
using ChecksumChunk = unordered_map<string, int>;

// path -> ChecksumChunk
using FileChecksumChunk = unordered_map<string, ChecksumChunk>;
// path -> vector of all Chunk Checksums (in order)
using FileChecksumVec = unordered_map<string, vector<string>>;

// 4096
#ifndef PAGESIZE
#define PAGE_SIZE 4096
#endif
#define CHUNK (PAGE_SIZE*2)

#include <fcntl.h> // O_RDONLY

class FileSync {
 private:
  FileChecksum lcl;  // local files

  vector<string> actions;
  void delete_file(string path) {
    actions.push_back("rm "+path);
  }

  string checksum(const char* buf) {
    auto MD5 = [&]() { return buf; }; // TODO
    return MD5();
  }

  void download_file(string relpath) { // fully downloads
    actions.push_back("dl "+relpath);
    string file_data="ABC";
    lcl.insert({relpath, checksum(file_data.c_str())});
  }

  void checksum_per_block(string path,
                                   vector<string>& vec,
                                   ChecksumChunk& mp) {

    int fd = open(path.c_str(), O_RDONLY);
    assert(fd >= 0);
    char buf[CHUNK];
    int i=0;
    while (true) {
      auto r = read(fd, buf, CHUNK);
      string csum = checksum(buf);
      mp.insert({csum, i++});
      vec.push_back(csum);
      if (r!=CHUNK) break;
    }
  }

  FileChecksum rmt_file_checksums() {
    FileChecksum rmp;
    // TCP COMMUNICATION
    return rmp;
  }

  void lcl_chunk_checksums(FileChecksum fetch_delta,
                           FileChecksumVec fcvec, FileChecksumChunk fcmp) {
    // path, file checksums
    for (auto f: fetch_delta) {
      ChecksumChunk mp; vector<string> vec;
      string path=f.first;
      checksum_per_block(path, vec, mp);

      fcvec.insert({path, vec});
      fcmp.insert({path, mp});
    }
  }

    void rmt_chunk_checksums(FileChecksum  fetch_delta,
                           FileChecksumVec vec, FileChecksumChunk mp) {
    // TCP COMMUNICATION
  }

 public:
  /** setup src, dest IPs, etc.. */
  FileSync() {}

  /** Pulls files from a remote.
			*
			* find which files we must:
   		* - create (fetch fully new files)
  			* - delete
			* - apply delta patches to remaining files
   */
  void sync() {
			
    auto rmt_files = rmt_file_checksums();
    FileChecksum fetch, fetch_delta; // these could be sets instead of map
			
    for (auto p: rmt_files) {
      if (!lcl.contains(p.first)) {
        fetch.insert({p.first, ""}); // must download fully
      } else {
        lcl.erase(p.first);
        if (p.second != lcl[p.first]) {
          // will fetch delta patches. we'll need more info
          fetch_delta.insert({p.first, ""});
        }
      }
    }

    // DELETIONS: whatever remained in local must be deleted
    for (auto to_del: lcl) delete_file(to_del.first);

    // INSERTIONS: new files
    for (auto new_file: fetch) download_file(new_file.first);

    // DELTA PATCHING: modified files
    if (!fetch_delta.empty()) {
      FileChecksumVec lcl_fcvec, rmt_fcvec;
      FileChecksumChunk lcl_fcmp, rmt_fcmp;

      lcl_chunk_checksums(fetch_delta, lcl_fcvec, lcl_fcmp);
      rmt_chunk_checksums(fetch_delta, rmt_fcvec, rmt_fcmp);

      // the #entries must match
      assert(lcl_fcvec.size() != rmt_fcvec.size());

      for (auto rmt_vec: rmt_fcvec) {
        auto lcl_vec = lcl_fcvec[rmt_vec.first];
        // figure out a merging strategy:
        // - things to consider:
        //   - something is prepended: few additions in front
        //   - something is appended: additions in the end
        //   - elsewhere, and combinations

        // + make a map of operations
        //   - chunk0: has to be fetched (new)
        //   - chunk1: gets from local chunk0
        // + execute them
      }
    }
			
    fetch.clear();
    fetch_delta.clear();
  }
};

int main() {
  // pseudo-code
}
