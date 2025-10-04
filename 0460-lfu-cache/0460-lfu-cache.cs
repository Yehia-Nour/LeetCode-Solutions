public class Node
{
    public int Key;
    public int Value;
    public int Frequency;
    public Node Prev;
    public Node Next;

    public Node(int key, int value)
    {
        Key = key;
        Value = value;
        Frequency = 1;
    }
}

public class LFUCache
{
    int _capacity;
    int _minFreq;
    Dictionary<int, Node> _nodes;
    Dictionary<int, LinkedList<Node>> _freqList; 

    public LFUCache(int capacity)
    {
        _capacity = capacity;
        _minFreq = 0;
        _nodes = new Dictionary<int, Node>();
        _freqList = new Dictionary<int, LinkedList<Node>>();
    }

    public int Get(int key)
    {
        if (!_nodes.ContainsKey(key))
            return -1;

        Node node = _nodes[key];
        UpdateFrequency(node);
        return node.Value;
    }

    public void Put(int key, int value)
    {
        if (_capacity == 0) return;

        if (_nodes.ContainsKey(key))
        {
            Node node = _nodes[key];
            node.Value = value;
            UpdateFrequency(node);
        }
        else
        {
            if (_nodes.Count >= _capacity)
            {
                LinkedList<Node> minFreqList = _freqList[_minFreq];
                Node nodeToRemove = minFreqList.Last.Value;
                minFreqList.RemoveLast();
                _nodes.Remove(nodeToRemove.Key);
                if (minFreqList.Count == 0)
                    _freqList.Remove(_minFreq);
            }

            Node newNode = new Node(key, value);
            _nodes[key] = newNode;
            _minFreq = 1;

            if (!_freqList.ContainsKey(1))
                _freqList[1] = new LinkedList<Node>();

            _freqList[1].AddFirst(newNode);
        }
    }

    private void UpdateFrequency(Node node)
    {
        int oldFreq = node.Frequency;
        _freqList[oldFreq].Remove(node);
        if (_freqList[oldFreq].Count == 0)
        {
            _freqList.Remove(oldFreq);
            if (_minFreq == oldFreq)
                _minFreq++;
        }

        node.Frequency++;
        if (!_freqList.ContainsKey(node.Frequency))
            _freqList[node.Frequency] = new LinkedList<Node>();

        _freqList[node.Frequency].AddFirst(node);
    }
}
