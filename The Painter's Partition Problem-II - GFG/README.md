# The Painter's Partition Problem-II
## Hard 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Dilpreet wants to paint&nbsp;his dog's home that has&nbsp;<strong style="user-select: auto;">n</strong> boards with&nbsp;different lengths. The length of i<sup style="user-select: auto;">th&nbsp;</sup>board is given by <strong style="user-select: auto;">arr[i]</strong> where <strong style="user-select: auto;">arr[]</strong> is an array of <strong style="user-select: auto;">n</strong> integers. He hired <strong style="user-select: auto;">k</strong> painters for this work and each painter takes <strong style="user-select: auto;">1 unit time to paint 1 unit of the board.&nbsp;</strong></span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">The problem is to find the minimum time to get this job done if all painters start together with the constraint&nbsp;that any painter will only paint continuous boards, say boards numbered <strong style="user-select: auto;">{2,3,4} </strong>or only board <strong style="user-select: auto;">{1}</strong> or nothing but not boards <strong style="user-select: auto;">{2,4,5}</strong>.</span></p>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>n = 5
k = 3
arr[] = {5,10,30,20,15}
<strong style="user-select: auto;">Output:</strong> 35
<strong style="user-select: auto;">Explanation: </strong>The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>n = 4
k = 2
arr[] = {10,20,30,40}
<strong style="user-select: auto;">Output: </strong>60
<strong style="user-select: auto;">Explanation: </strong>The most optimal way to paint:
Painter 1 allocation : {10,20,30}
Painter 2 allocation : {40}
Job will be complete at time = 60</span></pre>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your task:</strong><br style="user-select: auto;">
Your task is to complete the function <strong style="user-select: auto;">minTime() </strong>which takes the integers&nbsp;<strong style="user-select: auto;">n </strong>and&nbsp;<strong style="user-select: auto;">k</strong>&nbsp;and the array&nbsp;<strong style="user-select: auto;">arr[]</strong>&nbsp;as input and returns the minimum time required to paint all partitions.</span></p>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:</strong> O(n log m) , m = sum of all boards' length<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:</strong> O(1)</span></p>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 ≤ n ≤ 10<sup style="user-select: auto;">5</sup><br style="user-select: auto;">
1 ≤ k ≤ 10<sup style="user-select: auto;">5</sup><br style="user-select: auto;">
1 ≤ arr[i] ≤ 10<sup style="user-select: auto;">5</sup></span></p>
 <p style="user-select: auto;"></p>
            </div>