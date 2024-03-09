class Solution {
	public boolean isPalindrome(int x) {
		if (x < 0) {
			return false;
		}

		int xCopy = x;
		int reversed = 0;
		while (0 < xCopy) {
			reversed = reversed * 10 + xCopy % 10;
			xCopy /= 10;
		}

		return reversed == x;
	}
}
