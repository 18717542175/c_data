//删除有序数列中的重复项
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;

	int i = 0;
	int dst = 0;
	int j = 1;
	while (j < numsSize)
	{
		if (nums[i] == nums[j])
		{
			++j;
		}
		else {
			nums[dst] = nums[i];
			++dst;
			i = j;
			j++;
		}
	}
	nums[dst] = nums[i];
	++dst;
	return dst;
}