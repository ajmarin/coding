class Twitter:
    def __init__(self):
        self.follows = defaultdict(set)
        self.tweets = defaultdict(list)
        self.timestamp = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        tweets = self.tweets[userId]
        new_tweet = (self.timestamp, tweetId)
        if len(tweets) < 10:
            heappush(tweets, new_tweet)
        else:
            heapreplace(tweets, new_tweet)
        self.timestamp += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        most_recent = self.tweets[userId][:]
        for followed in self.follows[userId]:
            for data in self.tweets[followed]:
                if len(most_recent) < 10:
                    heappush(most_recent, data)
                elif data > most_recent[0]:
                    heapreplace(most_recent, data)
        ans = []
        while most_recent:
            ans.append(heappop(most_recent)[1])
        return ans[::-1]

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self.follows[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        followed = self.follows[followerId]
        if followeeId in followed:
            followed.remove(followeeId)
