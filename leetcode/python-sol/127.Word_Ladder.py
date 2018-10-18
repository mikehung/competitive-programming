import string
class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        wordList = set(wordList)
        if endWord not in wordList:
            return 0
        wordList.remove(endWord)
        if beginWord == endWord:
            return 1
        w = len(beginWord)
        beginWords = set([beginWord])
        endWords = set([endWord])
        level = 1
        while beginWords:
            if len(beginWords) > len(endWords):
                beginWords, endWords = endWords, beginWords
            newWords = set()
            for word in beginWords:
                for i in range(w):
                    for c in string.ascii_lowercase:
                        newWord = word[:i] + c + word[i+1:]
                        if newWord in endWords:
                            return level + 1
                        elif newWord in wordList:
                            wordList.remove(newWord)
                            newWords.add(newWord)
            beginWords = newWords
            level += 1
        return 0
