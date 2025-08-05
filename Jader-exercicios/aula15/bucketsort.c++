void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    for (float num : arr) {
        int index = n * num;
        buckets[index].push_back(num);
    }

    for (auto& bucket : buckets)
        sort(bucket.begin(), bucket.end());

    int idx = 0;
    for (auto& bucket : buckets)
        for (float num : bucket)
            arr[idx++] = num;
}
