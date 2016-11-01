def sort_and_count(a)
  n = a.length
  return [0, a] if n == 1
  x, b = sort_and_count(a[0...n/2])
  y, c = sort_and_count(a[n/2...n])
  z, d = merge_and_count(b, c)
  [x+y+z, d]
end

def merge_and_count(b,c)
  d = []
  n = b.length + c.length
  z = i = j = k = 0
  while k < n  do
    # If c[j].nil? then all items on the right array are gone
    # Ff b[i].nil? then all items on the left array are gone
    if c[j].nil? || (b[i] && b[i] < c[j])
      d[k] = b[i]
      i += 1
    else
      d[k] = c[j]
      j += 1
      z += (b.length - i)
    end
    k += 1
  end
  [z, d]
end

T = gets.strip.to_i
for a0 in (0..T-1)
    n = gets.strip.to_i
    q = gets.strip
    q = q.split(' ').map(&:to_i)

    msg = nil    # Check if Too chaotic
    q.each_with_index do |_v, i|
      if q[i] - i > 3
        msg = 'Too chaotic'
        break
      end
    end
    if msg
      puts msg
      next
    else
      inversions, _a = sort_and_count(q)
      puts inversions
    end
end