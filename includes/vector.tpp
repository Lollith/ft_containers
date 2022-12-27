/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:53 by agouet            #+#    #+#             */
/*   Updated: 2022/12/27 18:04:09 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T, typename Alloc>
Vector<T>::Vector() :_alloc(Allocator())
{}


template<typename T, typename Alloc>
Vector<T>::Vector( size_t n){}