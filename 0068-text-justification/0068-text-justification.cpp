class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;

        int prev = 0;
        while (prev < n) {                       // was: for loop fighting with prev
            string s = "";
            int cnt = prev;
            int currLength = 0;
            vector<string> em;

            // words so far + at least 1 space between each pair
            while (cnt < n && currLength + (int)words[cnt].length() + (int)em.size() <= maxWidth) {
                em.push_back(words[cnt]);        // was: s[i]
                currLength += words[cnt].length();
                cnt++;
            }

            int noOfWords = em.size();
            int extraSpace = maxWidth - currLength;

            // single word OR last line -> left justify
            if (noOfWords == 1 || cnt == n) {
                for (int k = 0; k < noOfWords; k++) {
                    s += em[k];
                    if (k != noOfWords - 1) s += ' ';
                }
                while ((int)s.size() < maxWidth) s += ' ';
            }
            else {
                int spaces = extraSpace / (noOfWords - 1);
                int ex = extraSpace % (noOfWords - 1);   // was: & instead of %
                for (int k = 0; k < noOfWords; k++) {
                    s += em[k];
                    if (k == noOfWords - 1) break;       // no spaces after last word
                    for (int t = 0; t < spaces; t++) s += ' ';
                    if (k < ex) s += ' ';                // leftmost gaps get +1
                }
            }

            ans.push_back(s);                            // was: never pushed
            prev = cnt;
        }
        return ans;                                      // was: never returned
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna