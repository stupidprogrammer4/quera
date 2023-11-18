#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define umap(a, b) unordered_map<a, b>
#define uset(a) unordered_set<a>
#define min_heap(a) priority_queue<a, vector<a>, greater<a>>


const int maxn = 300, oo = 1e9;
vector<pii> adj[maxn];
string id_to_stat[maxn];
umap(string, int) stat_to_id;
umap(string, uset(int)) lines_of_stat;

vector<vector<string>> lines = {
        {"Tajrish", "Gheytariyeh", "Shahid_Sadr", "Gholhak", "Doctor_Shari'ati", "Mirdamad", "Shahid_Haghani", "Shahid_Hemmat", "Mosalla-ye_Emam_Khomeini", "Shahid_Beheshti", "Shahid_Mofatteh", "Shohada-ye_Haftom-e_Tir", "Taleghani", "Darvazeh_Dowlat", "Sa'di", "Emam_Khomeini", "Panzdah-e_Khordad", "Khayyam", "Meydan-e_Mohammadiyeh", "Shoush", "Payaneh_Jonoub", "Shahid_Bokharaei", "Ali_Abad", "Javanmard-e_Ghassab", "Shahr-e_Rey", "Palayeshgah", "Shahed-Bagher_Shahr", "Haram-e_Motahhar-e_Emam_Khomeini", "Kahrizak"},
        {"Farhangsara", "Tehranpars", "Shahid_Bagheri", "Daneshgah-e_Elm-o_San'at", "Sarsabz", "Janbazan", "Fadak", "Sabalan", "Shahid_Madani", "Emam_Hossein", "Darvazeh_Shemiran", "Baharestan", "Mellat", "Emam_Khomeini", "Hasan_Abad", "Daneshgah-e_Emam_Ali", "Meydan-e_Hor", "Shahid_Navab-e_Safavi", "Shademan", "Daneshgah-e_Sharif", "Tarasht", "Tehran_Sadeghiyeh"},
        {"Gha'em", "Shahid_Mahallati", "Aghdasiyeh", "Nobonyad", "Hossein_Abad", "Meydan-e_Heravi", "Shahid_Zeynoddin", "Khajeh_Abdollah-e_Ansari", "Shahid_sayyad-e_Shirazi", "Shahid_Ghodousi", "Sohrevardi", "Shahid_Beheshti", "Mirza-ye_Shirazi", "Meydan-e_Jahad", "Meydan-e_Hazrat-e_Vali_Asr", "Teatr-e_Shahr", "Moniriyeh", "Mahdiyeh", "Rahahan", "Javadiyeh", "Zamzam", "Shahrak-e_Shari'ati", "Abdol_Abad", "Ne'mat_Abad", "Azadegan"},
        {"Shahid_Kolahdouz", "Nirou_Havaei", "Nabard", "Pirouzi", "Ebn-e_Sina", "Meydan-e_Shohada", "Darvazeh_Shemiran", "Darvazeh_Dowlat", "Ferdowsi", "Teatr-e_Shahr", "Meydan-e_Enghelab-e_Eslami", "Towhid", "Shademan", "Doctor_Habibollah", "Ostad_Mo'in", "Meydan-e_Azadi", "Bimeh", "Shahrk-e_Ekbatan", "Eram-e_Sabz"},
        {"Shahid_Sepahbod_Qasem_Soleimani", "Golshahr", "Mohammad_Shahr", "Karaj", "Atmosfer", "Garmdarreh", "Vardavard", "Iran_Khodro", "Chitgar", "Varzeshgah-e_Azadi", "Eram-e_Sabz", "Tehran_Sadeghiyeh"},
        {"Shahid_Sattari", "Shahid_Ashrafi_Esfahani", "Yadegar-e_Emam", "Marzdaran", "Shahrak-e_Azmayesh", "Daneshgah-e_Tarbiat_Modarres", "Meydan-e_Hazrat-e_Vali_Asr", "Shohada-ye_Haftom-e_Tir", "Emam_Hossein", "Meydan-e_Shohada", "Amir_Kabir", "Shahid_Rezaei", "Be'sat", "Kiyan_Shahr", "Dowlat_Abad"},
        {"Meydan-e_San'at", "Borj-e_Milad-e_Tehran", "Boostan-e_Goftegou", "Daneshgah-e_Tarbiat_Modarres", "Modafean-e_Salamat", "Towhid", "Shahid_Navab-e_Safavi", "Roudaki", "Komeyl", "Beryanak", "Helal_Ahmar", "Mahdiyeh", "Meydan-e_Mohammadiyeh", "Mowlavi", "Meydan-e_Ghiyam", "Chehel_Tan-e_Doulab", "Ahang", "Basij"},
    };

int another_line(string u, int l) {
    for (auto l1 : lines_of_stat[u])
        if (l1 != l) return l1;

    return 0;
}

void build_graph() {
    int l=1;
    for (auto line : lines) {
        for (int j=0; j<line.size()-1; j++) {
            adj[stat_to_id[line[j]+to_string(l)]].push_back({stat_to_id[line[j+1]+to_string(l)], 2});
            adj[stat_to_id[line[j+1]+to_string(l)]].push_back({stat_to_id[line[j]+to_string(l)], 2});
        }
        l++;
    }
}

void build_id() {
    uset(string) mark;
    int l=1, id=1, cid=150, ano_line;
    
    for (auto line : lines) {
        for (auto stat : line) {
            ano_line = another_line(stat, l);
            if (!ano_line) {
                stat_to_id[stat+to_string(l)] = id;
                id_to_stat[id] = stat+to_string(l);
                id++;
                continue;
            } 
            if (mark.find(stat) == mark.end()) {
                stat_to_id[stat+to_string(l)] = cid;
                id_to_stat[cid] = stat+to_string(l);
                stat_to_id[stat+to_string(ano_line)] = cid+1;
                id_to_stat[cid+1] = stat+to_string(ano_line);
                adj[cid].push_back({cid+1, 10});
                adj[cid+1].push_back({cid, 10});
                cid+=2;
                mark.insert(stat);
            }
        }
        l++;
    }
}

int dijkstra(string s, string f) {
    int src = stat_to_id[s], en = stat_to_id[f];
    vector<int> dist(maxn, oo);
    min_heap(pii) pq;
    pq.push({0, src});
    dist[src] = 0;

    while (pq.size()) {
        auto v = pq.top();
        pq.pop();
        int curr_node = v.second,
        curr_dist = v.first;

        if (curr_dist > dist[curr_node])
            continue;

        for (auto neighbor : adj[curr_node]) {
            int neighbor_node = neighbor.first,
            edge_weight = neighbor.second;

            int new_dist = dist[curr_node] + edge_weight;
            if (dist[neighbor_node] > new_dist) {
                dist[neighbor_node] = new_dist;
                pq.push({new_dist, neighbor_node});
            }
        }
    }
    return dist[en];
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l=1, id=1;
    for (auto line : lines) { 
        for (auto stat : line) 
            lines_of_stat[stat].insert(l);
        l++;
    }
    build_id();
    build_graph();

    int m;
    cin>>m;
    while (m--) {
        string s, f;
        cin>>s>>f;

        int ans = INT32_MAX;
        for (auto l1 : lines_of_stat[s]) 
            for (auto l2 : lines_of_stat[f])
                ans = min(ans, dijkstra(s+to_string(l1), f+to_string(l2)));

        cout<<12+17+ans<<'\n';        
        
    }
}