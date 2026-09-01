class Solution {
public:

    struct State {
        int x;
        int y;
        int energy;
        int mask;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sx = -1;
        int sy = -1;

        // Give every litter cell an ID
        vector<vector<int>> litterId(
            m, vector<int>(n, -1)
        );

        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // No litter -> already finished
        if (litterCount == 0) {
            return 0;
        }

        /*
            mask:

            1 = litter still NOT collected
            0 = litter already collected

            Example with 3 litter:

            111 -> none collected
            110 -> L0 collected
            100 -> L0 and L1 collected
            000 -> everything collected
        */

        int fullMask = (1 << litterCount) - 1;

        /*
            best[x][y][mask] = maximum energy with which
            we have reached (x,y) having this mask.

            We don't need energy as another dimension.

            If we have already reached the same
            (x,y,mask) with MORE energy, a state with
            less/equal energy can never be better.
        */

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << litterCount, -1)
            )
        );

        queue<State> q;

        // Starting state
        q.push({
            sx,
            sy,
            energy,
            fullMask
        });

        best[sx][sy][fullMask] = energy;

        int moves = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            // Process one BFS level
            while (sz--) {

                State cur = q.front();
                q.pop();

                int x = cur.x;
                int y = cur.y;
                int e = cur.energy;
                int mask = cur.mask;

                // All litter collected
                if (mask == 0) {
                    return moves;
                }

                /*
                    If energy is 0, we can only move if we
                    are currently standing on R.

                    But whenever we enter R, we immediately
                    restore energy, so normally we won't have
                    an energy-0 state on R.
                */
                if (e == 0) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Boundary check
                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n) {
                        continue;
                    }

                    // Can't enter obstacle
                    if (classroom[nx][ny] == 'X') {
                        continue;
                    }

                    int newEnergy;

                    /*
                        Every move normally costs 1 energy.

                        BUT if destination is R, the energy
                        gets restored to maximum.
                    */

                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }
                    else {
                        newEnergy = e - 1;
                    }

                    /*
                        If we moved to a normal cell and
                        energy became 0, that's allowed as
                        the final step, but we cannot make
                        another move from there.

                        So we DO NOT reject newEnergy == 0.
                    */

                    int newMask = mask;

                    // If we enter litter, collect it
                    if (classroom[nx][ny] == 'L') {

                        int id = litterId[nx][ny];

                        // Turn this bit OFF
                        newMask &= ~(1 << id);
                    }

                    /*
                        Dominance:

                        Suppose:

                        best[nx][ny][newMask] = 7

                        and we reach the same state with
                        energy = 5.

                        7 is better than 5, so skip it.
                    */

                    if (newEnergy <=
                        best[nx][ny][newMask]) {
                        continue;
                    }

                    // We found a better state
                    best[nx][ny][newMask] = newEnergy;

                    q.push({
                        nx,
                        ny,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};