class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for i in range(0, 31):
            total = sum(((num >> i) & 1) for num in nums)
            if total % 3:
                result |= (1 << i)
                temp = bin(result)
        total = sum(((num >> 31) & 1) for num in nums) 
        if total % 3:
            # result |= (1 << 31)
            result -= (1 << 31)
            temp = bin(result)
        return result