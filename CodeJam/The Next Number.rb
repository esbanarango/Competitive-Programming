file = File.exist?('in.in') ? File.new('in.in', 'r') : STDIN
output = File.open( "out.out","w" )
def next_bigger(num)
	num = num.to_s.chars
	size = num.length
	for i in (size-1).downto(1)
		rigth = num[i]
		left =  num[i-1]
		# The first place where the left-digit is less-than the right-digit is here.
		if left < rigth
			for j in (size-1).downto(i)
				# Find the smallest digit larger than rigth
				if left < num[j]
					num[i-1],num[j] = num[j],num[i-1]
					return (num[0..i-1] + num[i..size-1].sort).join
				end
			end
		end
	end
  (num << '0').join
end

n = file.gets.to_i

for i in (1..n)
	output << "Case ##{i}: " + next_bigger(file.gets.chomp.to_i) + "\n"
end