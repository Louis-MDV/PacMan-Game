/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:11 by louismdv          #+#    #+#             */
/*   Updated: 2023/11/23 10:35:34 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	wordcount(char const *s, int delimiter)
{
	int	i;
	int	count;
	int	slen;

	i = 0;
	count = 0;
	slen = ft_strlen(s);
	while (i < slen)
	{
		if (s[i] != delimiter && (s[i + 1] == delimiter || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strndup(char const *s, unsigned int n)
{
	char	*duplicate;

	duplicate = (char *)malloc((n + 1) * sizeof(char));
	if (duplicate == 0)
		return (0);
	ft_strlcpy(duplicate, s, n + 1);
	return (duplicate);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	strindex;
	unsigned int	i;
	unsigned int	sublen;

	i = 0;
	strindex = 0;
	if (!s)
		return (NULL);
	strings = ft_calloc((wordcount(s, c) + 1), sizeof(char *));
	if (!strings)
		return (NULL);
	while (strindex < wordcount(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		sublen = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			sublen++;
		}
		strings[strindex++] = ft_strndup((char *)s + i - sublen, sublen);
	}
	return (strings);
}

/* void free_strings(char **strings) {
    if (strings) {
        for (int i = 0; strings[i]; i++) {
            free(strings[i]);
        }
        free(strings);
    }
}

int main() {
    char input[] = "apple,orange,banana";
    int delimiter = ',';

    // Call ft_split to get the array of strings
    char **result = ft_split(input, delimiter);

    if (result) {
        printf("Split Strings:\n");
        for (int i = 0; result[i]; i++) {
            printf("%s\n", result[i]);
        }

        // Free the allocated memory for the strings
        free_strings(result);
    } else {
        printf("Split failed!\n");
    }

    return 0;
}
 */