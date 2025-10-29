class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or_value = 0
        for num in nums:
            max_or_value |= num
        return self._count_subsets(nums, 0, 0, max_or_value)

    def _count_subsets(
        self, nums: List[int], index: int, c_or: int, t_or: int
    ) -> int:

        if index == len(nums):
            return 1 if c_or == t_or else 0

        count_without = self._count_subsets(
            nums, index + 1, c_or, t_or
        )

        count_with = self._count_subsets(
            nums, index + 1, c_or | nums[index], t_or
        )

        return count_without + count_with