#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class MetaData {
    public:
        string id;
        string videoName;
        string videoLocation;
        int durationInSeconds;
        vector<int> timeStamps;
        int likes;
        int views;
};

class MetaDataStore{
    unordered_map<string, MetaData> metaDataMap;
    public:
        void addMetaData(MetaData metaData) {
            metaDataMap[metaData.id] = metaData;
        }

        MetaData getMetaData(string id){
            return metaDataMap[id];
        }

        /*
            This type of system is needed for very large applications,
            that can afford eventual consistency;
            The metadata can be batched and updated once every few seconds;
        */
        bool incrementLikes(string id){
            try {
                metaDataMap[id].likes++;
                return true;
            } catch(const std::exception& e) {
                return false;
            }
        }

        bool incrementViews(string id){
            try {
                metaDataMap[id].views++;
                return true;
            } catch(const std::exception& e) {
                return false;
            }
        }
};