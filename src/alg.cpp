// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) count++;
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value)
{
  if (len < 2) return 0;
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int leftCount = 1;
      while (left + leftCount < right && arr[left] == arr[left + leftCount]) leftCount++;
      int rightCount = 1;
      while (right - rightCount > left && arr[right] == arr[right - rightCount]) rightCount++;
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        count += leftCount * rightCount;
        left += leftCount;
        right -= rightCount;
      }
    }
    else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}



int countPairs3(int* arr, int len, int value)
{
  if (len < 2) return 0;
  int count = 0;
  int i = 0;
  while (i < len - 1) {
    int currentVal = arr[i];
    int leftCount = 1;
    while (i + leftCount < len && arr[i + leftCount] == currentVal) leftCount++;
    int target = value - currentVal;
    int left = i + leftCount;
    int right = len - 1;
    int firstPos = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        firstPos = mid;
        right = mid - 1;
      }
      else if (arr[mid] < target) left = mid + 1;
      else right = mid - 1;
    }
    if (firstPos != -1) {
      left = firstPos;
      right = len - 1;
      int lastPos = firstPos;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
          lastPos = mid;
          left = mid + 1;
        }
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
      }
      int rightCount = lastPos - firstPos + 1;
      if (currentVal == target) count += leftCount * (leftCount - 1) / 2;
      else count += leftCount * rightCount;
    }
    i += leftCount;
  }
  return count;
}
