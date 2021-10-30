class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for i in range(0, 32):
            total = 0
            for num in nums:
                total += ((num >> i) & 1)
            if total % 3:
                if i == 31:
                    result -= (1 << i)
                else:
                    result |= (1 << i)
        return result