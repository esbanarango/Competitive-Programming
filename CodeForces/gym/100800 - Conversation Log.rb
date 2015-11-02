m = gets.to_i

messages = {}

while m > 0
	m -= 1
	message = gets
	words = message.split(' ')
	messages[words.first] ||= []
	messages[words.first] << words[1..-1]
end

words_to_count = messages.values.first.flatten

messages.values[1..-1].each do |words|
	 words_to_count = words_to_count & words.flatten
end

if words_to_count.empty?
	puts 'ALL CLEAR'
else
	ordered_words = Hash[words_to_count.map{ |word| [word,0] }]

	messages.values.flatten.each do |word|
		if ordered_words.key? word
			ordered_words[word] += 1
		end
	end

	ordered_words.sort{|a,b| (b[1] <=> a[1]) == 0 ? (a[0] <=> b[0]) : (b[1] <=> a[1]) }.each do |word|
		puts word[0]
	end
end

