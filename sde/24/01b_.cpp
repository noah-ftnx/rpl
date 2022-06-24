

class Solution {
 public:
  vector<string> maxNumOfSubstrings(string s) {
    /*
    1. no overlaps
    2. must contain all occurences of a particular letter

    adefaddaccc
        .      .

        do 1 pass:
        add to a map: limits: map: char -> range: l, r

        0123456789A
        adefaddaccc
            .

        a -> 0, 7 : substring: 0,7
                           d -> 1, 6
            e -> 2, 2
            f -> 3, 3
            c -> 8, 10

            sort:
        - start: descending, then length
                         - then solve it like overlapping courses... or trains in a platform..





                     if not exists: mp[char]={i,i}
                                                else: mp[char].second=i

                     add

                         substrings:
        adefaddaccc
            adefadda
                ef
                    e
                        f
                            ccc

                                abbaccd
                                    substrings:
        abbaccd
            abbacc
                abba
                    bb
                        cc
                            d

                                abba, cc d
                                         bb, cc, d <- shorter total len


                                             */
  }
};