# Maximize The Cut Segments
## Medium 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given an integer <strong style="user-select: auto;">N</strong> denoting the Length of a line segment. You need to cut the line segment in such&nbsp;a way that the cut length of a line segment each time is either <strong style="user-select: auto;">x</strong> , <strong style="user-select: auto;">y</strong> or <strong style="user-select: auto;">z</strong>. Here x, y, and z are integers.<br style="user-select: auto;">
After performing&nbsp;all the cut operations, your<strong style="user-select: auto;"> total number of cut segments must be maximum</strong>.</span></p>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 1:</span></strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Input:
</span></strong><span style="font-size: 18px; user-select: auto;">N = 4
x = 2, y = 1, z = 1
<strong style="user-select: auto;">Output: </strong>4<strong style="user-select: auto;">
Explanation:</strong>Total length is 4, and the cut
lengths are 2, 1 and 1.&nbsp; We can make
maximum 4 segments each of length 1.</span>
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 2:</span></strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Input:
</span></strong><span style="font-size: 18px; user-select: auto;">N = 5
x = 5, y = 3, z = 2
<strong style="user-select: auto;">Output: </strong>2<strong style="user-select: auto;">
Explanation: </strong>Here total length is 5,&nbsp;and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong><br style="user-select: auto;">
You only need to complete the function <strong style="user-select: auto;">maximizeTheCuts()&nbsp;</strong>that takes n, x, y, z as parameters and returns <strong style="user-select: auto;">max number cuts</strong>.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity</strong> : O(N)<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space</strong>: O(N)</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints</strong><br style="user-select: auto;">
1 &lt;= N, x, y, z &lt;= 10<sup style="user-select: auto;">4</sup></span></p>
 <p style="user-select: auto;"></p>
            </div>