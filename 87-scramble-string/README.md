<h2><a href="https://leetcode.com/problems/scramble-string/">87. Scramble String</a></h2><h3>Hard</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">We can scramble a string s to get a string t using the following algorithm:</p>

<ol style="user-select: auto;">
	<li style="user-select: auto;">If the length of the string is 1, stop.</li>
	<li style="user-select: auto;">If the length of the string is &gt; 1, do the following:
	<ul style="user-select: auto;">
		<li style="user-select: auto;">Split the string into two non-empty substrings at a random index, i.e., if the string is <code style="user-select: auto;">s</code>, divide it to <code style="user-select: auto;">x</code> and <code style="user-select: auto;">y</code> where <code style="user-select: auto;">s = x + y</code>.</li>
		<li style="user-select: auto;"><strong style="user-select: auto;">Randomly</strong>&nbsp;decide to swap the two substrings or to keep them in the same order. i.e., after this step, <code style="user-select: auto;">s</code> may become <code style="user-select: auto;">s = x + y</code> or <code style="user-select: auto;">s = y + x</code>.</li>
		<li style="user-select: auto;">Apply step 1 recursively on each of the two substrings <code style="user-select: auto;">x</code> and <code style="user-select: auto;">y</code>.</li>
	</ul>
	</li>
</ol>

<p style="user-select: auto;">Given two strings <code style="user-select: auto;">s1</code> and <code style="user-select: auto;">s2</code> of <strong style="user-select: auto;">the same length</strong>, return <code style="user-select: auto;">true</code> if <code style="user-select: auto;">s2</code> is a scrambled string of <code style="user-select: auto;">s1</code>, otherwise, return <code style="user-select: auto;">false</code>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s1 = "great", s2 = "rgeat"
<strong style="user-select: auto;">Output:</strong> true
<strong style="user-select: auto;">Explanation:</strong> One possible scenario applied on s1 is:
"great" --&gt; "gr/eat" // divide at random index.
"gr/eat" --&gt; "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --&gt; "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --&gt; "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --&gt; "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --&gt; "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s1 = "abcde", s2 = "caebd"
<strong style="user-select: auto;">Output:</strong> false
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s1 = "a", s2 = "a"
<strong style="user-select: auto;">Output:</strong> true
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">s1.length == s2.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= s1.length &lt;= 30</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">s1</code> and <code style="user-select: auto;">s2</code> consist of lowercase English letters.</li>
</ul>
</div>