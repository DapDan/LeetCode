int searchInsert(int* nums, int numsSize, int target) {
    int ini = 0, fim = numsSize - 1, meio;

    while (ini <= fim) {
        meio = ini + (fim - ini) / 2;

        if (nums[meio] == target)
            return meio;
        else if (nums[meio] < target)
            ini = meio + 1;
        else
            fim = meio - 1;
    }

    return ini;
}