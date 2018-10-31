import java.util.Arrays;
import java.util.Map;
import java.util.PriorityQueue;

class TopVotedCandidate {
    
    private int[] times;
    private int[] persons;
    
    // O(n)
    public TopVotedCandidate(int[] persons, int[] times) {
        this.times = new int[persons.length];
        this.persons = new int[persons.length];
        int h_person = -1;
        int h_vote = -1;
        Map<Integer, Integer> pv = new HashMap<>();
        for (int i = 0; i < persons.length; i ++) {
            int val = pv.getOrDefault(persons[i], 0); // nice
            pv.put(persons[i], val + 1);
            if (val + 1 >= h_vote) {
                h_vote = val + 1;
                h_person = persons[i];
            }
            this.times[i] = times[i];
            this.persons[i] = h_person;
        }
    }
    
    // O(logn)
    public int q(int t) {
        int ins_pos = Arrays.binarySearch(this.times, t);  // nice
        if (ins_pos >= 0) return this.persons[ins_pos];
        else return this.persons[-ins_pos - 2];
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */