def first_letter letter
	capitalize = letter == letter.upcase

	letter.downcase!

	letters = { 'a'..'b' => 'b', 'c' => 'c', 'd'..'e' => 'd', 'f'..'i' => 'g', 'j'..'l' => 'k', 'm'..'o' => 'n', 'p'..'r' => 'p', 's'..'z' => 't'}

	converted = letters.detect{|k,v| k === letter}.last
	capitalize ? converted.upcase : converted
end

def last_letter letter
	case letter.downcase
	when 'p','k','n'
		'oh'
	when 't'
		'uh'
	when 'b','d','g','c'
		'ah'
	else
		''
	end
end

def process_syllables syllables, first
	hard_consonants = %w(b c d g k n p t)
	syllables.map do |syllable|
		hard_consonants.each { |hard_consonant| syllable.gsub!(hard_consonant,first) }
		syllable
	end
end

line = gets

words =
line.split(' ').map do |word|
	# All nimion words start with ‘hard’ consonants
	word = word.sub(/^./, first_letter(word.chars[0]))
	# Any hard consonant in subsequent syllables after the first one is remarkably better if it
	# is replaced with the same consonant as the one at the start of the word.
	if (syllables = word.split('-')).length > 1
		first_syllable = syllables[0]
		word = ([first_syllable] + process_syllables(syllables.drop(1),word.chars[0].downcase)).join('')
	end
	# No word ends in a hard consonant.
	word += last_letter(word.chars.last)
end

puts words.join(' ')


