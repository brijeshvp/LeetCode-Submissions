# Convert array into Zig-Zag fashion
## Easy
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given an array <strong style="user-select: auto;">Arr</strong> (distinct elements) of size <strong style="user-select: auto;">N</strong>. Rearrange the elements of array in zig-zag fashion. The converted array should be in form <strong style="user-select: auto;">a &lt; b &gt; c &lt; d &gt; e &lt; f.</strong> The relative order of elements is same in the output <strong style="user-select: auto;">i.e</strong> you have to iterate on the original array only.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>N = 7
Arr[] = {4, 3, 7, 8, 6, 2, 1}
<strong style="user-select: auto;">Output: </strong>3 7 4 8 2 6 1
<strong style="user-select: auto;">Explanation:</strong> 3 &lt; 7 &gt; 4 &lt; 8 &gt; 2 &lt; 6 &gt; 1</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>N = 4
Arr[] = {1, 4, 3, 2}
<strong style="user-select: auto;">Output:</strong> 1 4 2 3
<strong style="user-select: auto;">Explanation: </strong>1 &lt; 4 &gt; 2 &lt; 3</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong><br style="user-select: auto;">
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong style="user-select: auto;">zigZag()</strong>&nbsp;which takes the&nbsp;array of&nbsp;integers&nbsp;<strong style="user-select: auto;">arr&nbsp;</strong>and&nbsp;<strong style="user-select: auto;">n</strong><strong style="user-select: auto;">&nbsp;</strong>as parameters and returns void. You need to modify the array itself.<br style="user-select: auto;">
<strong style="user-select: auto;">NOTE:</strong> In the mentioned complexity, only a unique solution will exist.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:</strong>&nbsp;O(N)<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 &lt;= N &lt;= 10<sup style="user-select: auto;">5</sup><br style="user-select: auto;">
0 &lt;= Arr<sub style="user-select: auto;">i</sub> &lt;= 10<sup style="user-select: auto;">6</sup></span></p>

<p style="user-select: auto;">&nbsp;</p>
 <p style="user-select: auto;"></p>
            </div>