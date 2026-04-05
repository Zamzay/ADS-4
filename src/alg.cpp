// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
  if (len < 2) return 0;
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  if (len < 2) return 0;
  int count = 0;
  int left = 0;
  int right = len - 1;
  
  while (left < right) {
    int sum = arr[left] + arr[right];
    
    if (sum == value) {
      int leftVal = arr[left];
      int rightVal = arr[right];
      
      int leftCount = 0;
      while (left + leftCount < len && arr[left + leftCount] == leftVal) {
        leftCount++;
      }
      
      int rightCount = 0;
      while (right - rightCount >= 0 && arr[right - rightCount] == rightVal) {
        rightCount++;
      }
      
      if (leftVal == rightVal) {
        int total = right - left + 1;
        count += total * (total - 1) / 2;
        break;
      } else {
        count += leftCount * rightCount;
        left += leftCount;
        right -= rightCount;
      }
    } else if (sum < value) {
      int current = arr[left];
      while (left < len && arr[left] == current) {
        left++;
      }
    } else {
      int current = arr[right];
      while (right >= 0 && arr[right] == current) {
        right--;
      }
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  if (len < 2) return 0;
  int count = 0;
  
  for (int i = 0; i < len - 1; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    
    int target = value - arr[i];
    
    int left = i + 1;
    int right = len - 1;
    bool found = false;
    
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        found = true;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    
    if (found) {
      int leftCount = 1;
      int tempI = i + 1;
      while (tempI < len && arr[tempI] == arr[i]) {
        leftCount++;
        tempI++;
      }
      
      int rightCount = 0;
      for (int j = i + 1; j < len; j++) {
        if (arr[j] == target) {
          rightCount++;
        }
      }
      
      if (arr[i] == target) {
        count += leftCount * (leftCount - 1) / 2;
        i += leftCount - 1;
      } else {
        count += leftCount * rightCount;
      }
    }
  }
  return count;
}
