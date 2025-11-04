from typing import List


class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:

        def convert(a):
            for i in 'aeiou':
                a = a.replace(i,'*')
            return a
        
        res = []
        case_map = dict()
        vowel_match = dict()

        for word in wordlist:
            case_map.setdefault(word.lower(),word)
            vowel_match.setdefault(convert(word.lower()),word) 
        
        wordlist = set(wordlist)

        for word in queries:
            
            if word in wordlist:
                res.append(word)
            
            elif word.lower() in case_map:
                res.append(case_map[word.lower()])
            
            elif convert(word.lower()) in vowel_match:
                res.append(vowel_match[convert(word.lower())])
            
            else:
                res.append("")

        wordlist.clear()
        case_map.clear()
        vowel_match.clear()

        return res
