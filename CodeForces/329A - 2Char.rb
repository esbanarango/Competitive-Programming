require 'set'

file = File.exist?('in.in') ? File.new('in.in', 'r') : STDIN

def init_both(char1,char2)
  total = 0
  [char1,char2].each do |char|
    if @global_count[char]
      total += @global_count[char]
    end
  end
  total
end

n = file.gets.to_i
@global_count = {}
global_words = {}

while n > 0 do
  n -= 1
  word = file.gets.chomp

  valid_word = true
  char1 = word.chars.first
  char2 = nil
  current_count = {}
  word.chars.each do |char|
    char2 ||= char if char != char1
    if char != char1 && char != char2
      valid_word = false
      break
    end
    current_count[char] ||= 0
    current_count[char] += 1
  end
  if valid_word
    if char2
      both_key = "#{char1}#{char2}".chars.sort.join
      @global_count[both_key] ||= init_both(char1,char2)
      @global_count[both_key] += word.length
      global_words[char1] ||= Set.new [char1]
      global_words[char1].add both_key
      global_words[char2] ||= Set.new [char2]
      global_words[char2].add both_key
    else
      @global_count[char1] ||= 0
      global_words[char1] ||= Set.new [char1]
      global_words[char1].add char1

      global_words[char1].each do |char|
        @global_count[char] += word.length
      end
    end
  end
end
# Generate all possible combinations for every single word with word.length == 1
global_words.each do |k,v|
	if k.length == 1
		global_words.each do |q,b|
			both_key = "#{q}#{k}".chars.sort.join
			if q != k && q.length == 1
				global_words[k].add both_key
				@global_count[both_key] ||= init_both(k,q)
			end
		end
	end
end

@global_count = @global_count.sort {|a1,a2| a2[1] <=> a1[1] }
@global_count = Hash[*@global_count.flatten]
puts @global_count.values.first || 0

# Super way clever solution
# n = gets.chomp.to_i
# d = Hash.new(0)
# n.times do
#   word = gets.chomp
#   k = word.split("").uniq.sort
#   v = word.length
#   d[k] += v if k.length <= 2
# end
# res = 0
# (?a..?z).to_a.combination(2) do |kk|
#   res = [res, d[[kk[0]]] + d[[kk[1]]] + d[kk]].max
# end
# puts res