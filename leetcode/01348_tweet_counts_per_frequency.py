class TweetCounts:
    def __init__(self):
        self.bucket_size = {
            "minute": 60,
            "hour": 60 * 60,
            "day": 24 * 60 * 60,
        }
        self.tweet_times = collections.defaultdict(collections.deque)

    def recordTweet(self, tweetName: str, time: int) -> None:
        self.tweet_times[tweetName].append(time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        size = self.bucket_size[freq]
        counts = [0] * (1 + (endTime - startTime) // size)
        for t in self.tweet_times[tweetName]:
            if startTime <= t <= endTime:
                counts[(t - startTime) // size] += 1
        return counts