using namespace std;

#include <iostream>

int main(void) {
    int JACK[1000000];
    int N, M;
    while (1) {
        cin >> N >> M;
        if ( (N == 0) && (M == 0) ) {
            break;
        }

        int disk;
        for (int i = 0; i < N; i++) {
            cin >> disk;
            JACK[i] = disk;
        }
        
        int i = 0;
        int common_disks_count = 0;
        for (int j = 0; j < M; j++) {
            cin >> disk;
            
            if (i >= N) {
                continue;
            }

            while ( (i < N) && (JACK[i] < disk) ) {
                i++;
            }

            if ( (i < N) && (JACK[i] == disk) ) {
                i++;
                common_disks_count++;
            }
        }
        cout << common_disks_count << endl;
    }
}