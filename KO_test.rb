# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    KO_test.rb                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 23:04:41 by user42            #+#    #+#              #
#    Updated: 2021/04/29 18:25:41 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if ARGV.length != 2
	puts "KO_test.ruby: wrong number of arguments, requires 2 integers \n\t- usage: mean.ruby [number of tests] [number of values]"
	exit 1
end

working = ['|', '/', '-', '\\', '|', '/', '-', '\\']

for i in 1..ARGV[0].to_i
	print "running test #{i}/#{ARGV[0].to_i} ... #{working[i % working.length]}\r"
	$stdout.flush
	random_values = (-9999..9999).to_a.sample(ARGV[1].to_i).join(' ')
	results = `./push_swap #{random_values} | ./checker #{random_values}`
	if results.strip.upcase != "OK" && results.strip.upcase != ""
		puts "\n#{results.strip.upcase} with values:\n#{random_values}"
		exit 1
	end
end

puts "\nOK"