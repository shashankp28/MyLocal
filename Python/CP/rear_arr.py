#User function Template for python3
class Solution:
    ##Complete this function
    #Function to rearrange  the array elements alternately.
    def rearrange(self,arr, n):
        i = 0
        arr[i], arr[n-1] = arr[n-1], arr[i]
        print(arr)
        i+=1
        counter = 0
        j = n-1
        while i<n-1:
            print((i, j))
            arr[i], arr[j] = arr[j], arr[i]
            print(arr)
            if j==n-1: 
                counter+=1
                j = n-1-counter
            else:
                j+=1
            i+=1
        return arr

obj = Solution()
obj.rearrange([1, 2, 3, 4, 5, 6], 6)