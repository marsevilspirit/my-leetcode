int** ret;
int* str;
int* record;
int strTop;
int retTop;
int* tmp;

void backtrack(int* nums,int numsSize,int index)
{
  if(index==numsSize)
  {
      int* str_tmp=malloc(sizeof(int)*numsSize);
      for(int i=0;i<numsSize;i++)
      {
          str_tmp[i]=str[i];
      }
      ret[retTop]=str_tmp;
      record[retTop++]=strTop;
      return;
  }
  for(int i=0;i<numsSize;i++)
  {
      if(tmp[i]!=0)
      {
          continue;
      }
      tmp[i]=1;
      str[strTop++]=nums[i];
      backtrack(nums, numsSize, index+1);
      strTop--;
      tmp[i]=0;

  }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
  ret=malloc(sizeof(int*)*40000);
  str=malloc(sizeof(int)*numsSize);
  record=malloc(sizeof(int)*40000);
  tmp=malloc(sizeof(int)*numsSize);
  memset(tmp, 0, sizeof(int)*numsSize);
  strTop=retTop=0;
  backtrack(nums, numsSize, 0);
  * returnSize=retTop;
  * returnColumnSizes=record;
  return ret;

}

