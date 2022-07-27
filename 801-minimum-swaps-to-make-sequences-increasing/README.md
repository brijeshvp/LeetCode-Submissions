<h2><a href="https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/">801. Minimum Swaps To Make Sequences Increasing</a></h2><h3>Hard</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given two integer arrays of the same length <code style="user-select: auto;">nums1</code> and <code style="user-select: auto;">nums2</code>. In one operation, you are allowed to swap <code style="user-select: auto;">nums1[i]</code> with <code style="user-select: auto;">nums2[i]</code>.</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;">For example, if <code style="user-select: auto;">nums1 = [1,2,3,<u style="user-select: auto;">8</u>]</code>, and <code style="user-select: auto;">nums2 = [5,6,7,<u style="user-select: auto;">4</u>]</code>, you can swap the element at <code style="user-select: auto;">i = 3</code> to obtain <code style="user-select: auto;">nums1 = [1,2,3,4]</code> and <code style="user-select: auto;">nums2 = [5,6,7,8]</code>.</li>
</ul>

<p style="user-select: auto;">Return <em style="user-select: auto;">the minimum number of needed operations to make </em><code style="user-select: auto;">nums1</code><em style="user-select: auto;"> and </em><code style="user-select: auto;">nums2</code><em style="user-select: auto;"> <strong style="user-select: auto;">strictly increasing</strong></em>. The test cases are generated so that the given input always makes it possible.</p>

<p style="user-select: auto;">An array <code style="user-select: auto;">arr</code> is <strong style="user-select: auto;">strictly increasing</strong> if and only if <code style="user-select: auto;">arr[0] &lt; arr[1] &lt; arr[2] &lt; ... &lt; arr[arr.length - 1]</code>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> nums1 = [1,3,5,4], nums2 = [1,2,3,7]
<strong style="user-select: auto;">Output:</strong> 1
<strong style="user-select: auto;">Explanation:</strong> 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
<strong style="user-select: auto;">Output:</strong> 1
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">2 &lt;= nums1.length &lt;= 10<sup style="user-select: auto;">5</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">nums2.length == nums1.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= nums1[i], nums2[i] &lt;= 2 * 10<sup style="user-select: auto;">5</sup></code></li>
</ul>
</div>