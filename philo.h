#include <time.h>
#include <unistd.h>

// typedef struct s_philo
// {
// 	int				id;
// 	struct s_global	*data;
// }	t_philo;

typedef struct s_global
{
    int             tm_die;
	int				nb_philo;
	int				max_meals;
	int				tm_sleep;
	int		        tm_eat;
}					t_global;
