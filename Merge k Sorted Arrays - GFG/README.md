# Merge k Sorted Arrays
## Medium 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given <strong style="user-select: auto;">K</strong> sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.<br style="user-select: auto;">
<strong style="user-select: auto;">Example 1:</strong> </span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
<strong style="user-select: auto;">Output: </strong>1&nbsp;2&nbsp;3&nbsp;4&nbsp;5 6 7 8 9<strong style="user-select: auto;">
Explanation:</strong>Above test case has 3&nbsp;sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6],&nbsp;
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong> </span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>K = 4
arr[][]={{1,2,3,4}{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
<strong style="user-select: auto;">Output:
</strong>1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9&nbsp;<strong style="user-select: auto;">
Explanation: </strong>Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2],&nbsp;[3, 3, 4, 4],
[5, 5, 6, 6]&nbsp; [7, 8, 9, 9&nbsp;]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
6, 6, 7, 8, 9, 9&nbsp;].</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your&nbsp;Task:</strong><br style="user-select: auto;">
You do not need to read input or print anything. Your task is to complete&nbsp;<strong style="user-select: auto;">mergeKArrays</strong>() function which takes 2 arguments, an arr[K][K] 2D Matrix containing K&nbsp;sorted arrays and an integer K denoting the number of sorted arrays, as input and returns the merged sorted array ( as a pointer to the merged sorted arrays in <strong style="user-select: auto;">cpp,&nbsp;</strong>as an ArrayList in&nbsp;<strong style="user-select: auto;">java,&nbsp;</strong>and list in&nbsp;<strong style="user-select: auto;">python</strong>)</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:</strong>&nbsp;O(K<sup style="user-select: auto;">2</sup></span>*<span style="font-size: 18px; user-select: auto;">Log(K))<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:</strong>&nbsp;O(K)</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints</strong>:<br style="user-select: auto;">
1 &lt;= K &lt;= 100</span></p>
 <p style="user-select: auto;"></p>
            </div>