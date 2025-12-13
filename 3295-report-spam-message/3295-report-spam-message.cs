public class Solution
{
    public bool ReportSpam(string[] message, string[] bannedWords)
    {
        HashSet<string> spamWords = [];

        for (int i = 0; i < bannedWords.Length; i++)
            spamWords.Add(bannedWords[i]);

        int count = 0;

        foreach (var word in message)
        {
            if (spamWords.Contains(word))
            {
                count++;
                if (count > 1)
                    return true;
            }
        }

        return false;
    }
}