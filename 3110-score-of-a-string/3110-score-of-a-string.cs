
public class Solution
{
    public int ScoreOfString(string s)
    {
        int score = 0;

        for (int i = 0; i < s.Length - 1; i++)
            score += Math.Abs(s[i] - s[i + 1]);

        return score;
    }
}


