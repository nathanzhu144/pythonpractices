#  Suppose that we are trying to find the maximum sum that can be derived from an array
#  However, no two consecutive items in the array can be taken.
# 
#  Formally, the idea is that we have a line of houses.  
#  https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
#
#  10:24 am, Sunday Nov 4th, Hilton Hotel in Chicago
#
#  Each of the houses has a profit, given in "arr".  
# 
#  The key insight is ... 
# 
#  We can either take or not take the last house.  
# 
#  1. If we take the last house
#  we cannot take the last house or second to last house, so the problem breaks down to
#  a smaller problem of all the houses except for the last 2.
#
#  2. If we do not take the last house, the problem breaks down to all the houses minus 1.
#
#  We take maximum of the two possibilities.
#
#  [1, 2, 3, ... P - 2, P - 2, P]
#                
#           to maximum of
#  [1, 2, 3, ... P - 2] + profit from last house 
#                  OR 
#  [1, 2, 3, ... P - 1] + no profit 
#
#  

def max_no_adjacent(arr):
    def helper(arr, i, mem):
        key = i
        if key in mem:
            return mem[key]

        if i < 0:
            return 0

        if i == 0:
            return arr[i]

        else:
            mem[i] = max(helper(arr, i - 1, mem), helper(arr, i - 2, mem) + arr[i])

        return mem[i]

    return helper(arr, len(arr) - 1, {})

if __name__ == "__main__":
    # should be 110
    print(max_no_adjacent([5, 5, 10, 100, 10, 5]))
    print(max_no_adjacent([1, 20, 3]))
    print(max_no_adjacent([1, 2, 3]))
    print(max_no_adjacent([6, 7, 1, 3, 8, 2, 4]))