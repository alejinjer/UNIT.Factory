#include "pathfinder.h"

static bool is_visited(t_link *visited, t_island *i)
{
    t_link *iter = visited;

    if (!iter)
        return false;
    while (iter)
    {
        if (iter->linked_island->name == i->name)
            return true;
        iter = iter->next;
    }
    return false;
}

static void find_path(t_main *m, t_link *visited, int weight, t_path **paths)
{
    t_link *iter = m->start->links;
    t_link *visited_island = NULL;

    if (is_visited(visited, m->start))
        return;
    visited_island = mx_create_link(m->start);
    visited_island->weight = weight;
    mx_push_back_link(&visited, visited_island);
    if (m->start == m->end)
        mx_add_path(&paths[m->end->index], mx_create_path(visited));
    else
        while (iter)
        {
            m->start = iter->linked_island;
            find_path(m, visited, iter->weight, paths);
            iter = iter->next;
        }
    mx_pop_back_link(&visited);
}

void mx_find_all_paths(t_main *m)
{
    m->start = m->islands;
    t_link *visited = NULL;

    while (m->start)
    {
        m->end = m->start->next;
        m->start_remainder = m->start;
        while (m->end)
        {
            if (m->start != m->end)
            {
                find_path(m, visited, 0, m->start->paths);
                m->start = m->start_remainder;
            }
            m->end = m->end->next;
        }
        m->start = m->start->next;
    }
}
