class disjointSet {
public:
	vector<int> parent , rank ,size;

	disjointSet(int n) {
		parent.resize(n + 1);
		size.resize(n + 1 , 1);
		for(int i = 0; i <= n; i++) {
			parent[i] = i;
		}
		rank.resize(n + 1 , 0);
	}

	int ulp(int node) {
		if(node == parent[node]) return node;

		return parent[node] = ulp(parent[node]);
	}

	bool UnionByRank(int u , int v) {
		int ulp_u = ulp(u);
		int ulp_v = ulp(v);

		if(ulp_u == ulp_v) return false;

		if(rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;	
		}
		else if(rank[ulp_u] > rank[ulp_v]) {
			parent[ulp_v] = ulp_u;
		}
		else {
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
		return true;
	}

	bool UnionBySize(int u , int v) {
		int ulp_u = ulp(u);
		int ulp_v = ulp(v);

		if(ulp_u == ulp_v) return false;

		if(size[ulp_u] < size[ulp_v]) {
			size[ulp_v] += size[ulp_u];
			parent[ulp_u] = ulp_v;
		}
		else {
			size[ulp_u] += size[ulp_v];
			parent[ulp_v] = ulp_u;
		}
		return true;
	}
};
