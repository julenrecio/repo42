cat /etc/passwd | awk 'NR%2==0'| awk 'NR >= '$FT_LINE1' && NR <= '$FT_LINE2'' | cut -f1 -d ':' | rev | sort -r  | paste -sd, | sed 's/,/, /g; s/$/./'
