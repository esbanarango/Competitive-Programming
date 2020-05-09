n, k = gets.chomp.split.map(&:to_i)
vec = gets.chomp.split.map(&:to_i)
INF = 10 ** 12
dp = []
dp << 0
dp << (vec[0] - vec[1]).abs
1.upto(n - 1) do |i|
  min = INF
  [i - k, 0].max.upto(i - 1) do |j|
    cost = dp[j] + (vec[i] - vec[j]).abs
    min = cost if cost < min
  end
  dp << min
end
puts dp[n - 1]