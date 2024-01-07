    double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
        int totalSize = nums1Size + nums2Size;
        if(totalSize % 2 == 1) 
        {
            int max = -0x3f3f3f3f;
            int j = 0, k = 0;
            for(int i = 0; i < totalSize/2+1; i++)
            {
                if (j < nums1Size && (k >= nums2Size || nums1[j] < nums2[k]) && nums1Size != 0)
                {
                    max = nums1[j];
                    j++;
                }
                else if (k < nums2Size)
                {
                    max = nums2[k];
                    k++;
                }
            }
            return max;
        }
        float first = -1000000, second = -1000000;
        int j = 0, k = 0;
        for(int i = 0; i < totalSize/2+1; i++)
        {
            if(j < nums1Size && (k >= nums2Size || nums1[j] < nums2[k]))
            {
                second = first;
                first = nums1[j];
                j++;
            }
            else if(k < nums2Size)
            {
                second = first;
                first = nums2[k];
                k++;
            }
        }
        return (first+second)/2;
    }
