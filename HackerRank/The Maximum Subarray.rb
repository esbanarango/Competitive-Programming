
file = File.exist?('in.in') ? File.new('in.in', 'r') : STDIN
MAX = 10000

cases = file.gets.chomp.to_i
cases.times do
	file.gets.chomp # no need this
	numbers = file.gets.chomp
  max_sum = 0;
  current_max = max_contiguous_sum = (-1 * MAX);
	numbers.split(' ').each do |a|
		a = a.to_i
		current_max = [a,current_max + a].max
		max_contiguous_sum = [current_max,max_contiguous_sum].max
		max_sum += a if a > 0
	end
 	max_sum = max_contiguous_sum if (max_contiguous_sum < 0)
 	puts "#{max_contiguous_sum} #{max_sum}"
end