class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        return all(nums[i] == nums[~i] for i in range(len(nums) // 2))
