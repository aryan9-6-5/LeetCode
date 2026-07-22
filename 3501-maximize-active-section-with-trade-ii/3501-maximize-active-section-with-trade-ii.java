import java.util.*;

class Group {
    int start;
    int length;

    Group(int start, int length) {
        this.start = start;
        this.length = length;
    }
}

class SparseTable {
    int[][] st;
    int n;

    SparseTable(int[] nums) {
        n = nums.length;
        if (n == 0) {
            st = new int[1][1];
            return;
        }

        int log = 32 - Integer.numberOfLeadingZeros(n);
        st = new int[log][n];

        System.arraycopy(nums, 0, st[0], 0, n);

        for (int k = 1; k < log; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = Math.max(
                    st[k - 1][i],
                    st[k - 1][i + (1 << (k - 1))]
                );
            }
        }
    }

    int query(int l, int r) {
        if (l > r || n == 0) return 0;
        int k = 31 - Integer.numberOfLeadingZeros(r - l + 1);
        return Math.max(st[k][l], st[k][r - (1 << k) + 1]);
    }
}

class Solution {

    public List<Integer> maxActiveSectionsAfterTrade(String s, int[][] queries) {
        int n = s.length();
        int ones = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') ones++;
        }

        List<Group> zeroGroups = new ArrayList<>();
        int[] zeroGroupIndex = new int[n];

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
                if (i > 0 && s.charAt(i - 1) == '0') {
                    zeroGroups.get(zeroGroups.size() - 1).length++;
                } else {
                    zeroGroups.add(new Group(i, 1));
                }
            }
            zeroGroupIndex[i] = zeroGroups.size() - 1;
        }

        if (zeroGroups.isEmpty()) {
            List<Integer> ans = new ArrayList<>();
            for (int i = 0; i < queries.length; i++) ans.add(ones);
            return ans;
        }

        int[] merge = new int[Math.max(0, zeroGroups.size() - 1)];
        for (int i = 0; i + 1 < zeroGroups.size(); i++) {
            merge[i] = zeroGroups.get(i).length + zeroGroups.get(i + 1).length;
        }

        SparseTable st = new SparseTable(merge);
        List<Integer> ans = new ArrayList<>();

        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];

            int active = ones;

            int left = (zeroGroupIndex[l] == -1) 
                ? -1 
                : (zeroGroups.get(zeroGroupIndex[l]).length - (l - zeroGroups.get(zeroGroupIndex[l]).start));

            int right = (zeroGroupIndex[r] == -1) 
                ? -1 
                : (r - zeroGroups.get(zeroGroupIndex[r]).start + 1);

            int gL = zeroGroupIndex[l];
            int gR = zeroGroupIndex[r];

            int startAdjacent = gL + 1;
            int endAdjacent = (s.charAt(r) == '1' ? gR : gR - 1) - 1;

            if (s.charAt(l) == '0' && s.charAt(r) == '0' && gL + 1 == gR) {
                active = Math.max(active, ones + left + right);
            } else if (startAdjacent <= endAdjacent && merge.length > 0) {
                active = Math.max(active, ones + st.query(startAdjacent, endAdjacent));
            }

            if (s.charAt(l) == '0' && gL + 1 <= (s.charAt(r) == '1' ? gR : gR - 1)) {
                active = Math.max(
                    active,
                    ones + left + zeroGroups.get(gL + 1).length
                );
            }

            if (s.charAt(r) == '0' && gL < gR - 1) {
                active = Math.max(
                    active,
                    ones + right + zeroGroups.get(gR - 1).length
                );
            }

            ans.add(active);
        }

        return ans;
    }
}