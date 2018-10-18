class Solution:
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        unique_words = set()
        for word in words:
            word_lst = []
            for c in word:
                word_lst.append(code[ord(c)-ord('a')])
            unique_words.add(''.join(word_lst))

        return len(unique_words)



words = ["gin", "zen", "gig", "msg"]
print(Solution().uniqueMorseRepresentations(words))
