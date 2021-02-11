class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        
        
        needle_size =  len(needle)
        haystack_size = len(haystack)
        
        for i in range(0,haystack_size-needle_size):
            if (needle == haystack[i:i+needle_size]):
                return i;
        return -1;