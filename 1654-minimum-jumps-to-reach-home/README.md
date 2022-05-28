<h2><a href="https://leetcode.com/problems/minimum-jumps-to-reach-home/">1654. Minimum Jumps to Reach Home</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">A certain bug's home is on the x-axis at position <code style="user-select: auto;">x</code>. Help them get there from position <code style="user-select: auto;">0</code>.</p>

<p style="user-select: auto;">The bug jumps according to the following rules:</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;">It can jump exactly <code style="user-select: auto;">a</code> positions <strong style="user-select: auto;">forward</strong> (to the right).</li>
	<li style="user-select: auto;">It can jump exactly <code style="user-select: auto;">b</code> positions <strong style="user-select: auto;">backward</strong> (to the left).</li>
	<li style="user-select: auto;">It cannot jump backward twice in a row.</li>
	<li style="user-select: auto;">It cannot jump to any <code style="user-select: auto;">forbidden</code> positions.</li>
</ul>

<p style="user-select: auto;">The bug may jump forward <strong style="user-select: auto;">beyond</strong> its home, but it <strong style="user-select: auto;">cannot jump</strong> to positions numbered with <strong style="user-select: auto;">negative</strong> integers.</p>

<p style="user-select: auto;">Given an array of integers <code style="user-select: auto;">forbidden</code>, where <code style="user-select: auto;">forbidden[i]</code> means that the bug cannot jump to the position <code style="user-select: auto;">forbidden[i]</code>, and integers <code style="user-select: auto;">a</code>, <code style="user-select: auto;">b</code>, and <code style="user-select: auto;">x</code>, return <em style="user-select: auto;">the minimum number of jumps needed for the bug to reach its home</em>. If there is no possible sequence of jumps that lands the bug on position <code style="user-select: auto;">x</code>, return <code style="user-select: auto;">-1.</code></p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
<strong style="user-select: auto;">Output:</strong> 3
<strong style="user-select: auto;">Explanation:</strong> 3 jumps forward (0 -&gt; 3 -&gt; 6 -&gt; 9) will get the bug home.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
<strong style="user-select: auto;">Output:</strong> -1
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
<strong style="user-select: auto;">Output:</strong> 2
<strong style="user-select: auto;">Explanation:</strong> One jump forward (0 -&gt; 16) then one jump backward (16 -&gt; 7) will get the bug home.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= forbidden.length &lt;= 1000</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= a, b, forbidden[i] &lt;= 2000</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= x &lt;= 2000</code></li>
	<li style="user-select: auto;">All the elements in <code style="user-select: auto;">forbidden</code> are distinct.</li>
	<li style="user-select: auto;">Position <code style="user-select: auto;">x</code> is not forbidden.</li>
</ul>
</div>