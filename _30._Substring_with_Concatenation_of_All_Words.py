from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        l = len(words[0])
        total = len(words) * l

        def frequency_map(word_list):
            freq = {}
            for ch in word_list:
                freq[ch] = freq.get(ch, 0) + 1
            return freq

        main = frequency_map(words)
        result = []

        for start in range(0, len(s) - total + 1):
            s_parts = [s[i:i + l] for i in range(start, start + total, l)]
            if frequency_map(s_parts) == main:
                result.append(start)

        return result

