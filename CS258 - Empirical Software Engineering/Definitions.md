**Note:**  this document is in no logical order

## Population Mean
Sum of set / Length of set
```haskell
mean xs = sum xs / length xs
```

## Sample Mean
Sum of Set / (Length of Set - 1)
```haskell
sampleMean xs = sum xs / (length xs - 1)
```
### μ  = Mean of population
### x̄ = Mean of Sample

## Variance
Measures how much the data differs from the mean.  If variance is large, then
the data is spread out.

![Variance](http://www.statisticslectures.com/images/samplevarstd.gif)

```haskell
variance = 1/(n-1) * sum ((x - x̄)^2)
  where x' = mean of data

variance = s^2
```

## Inter-Quartile Range
Used to cut out outliers  
`iqr = Upper Quartile - Lower Quartile`

## Skew
### Long Tailed Distribution
Contains values far from the body of data

### Short Tailed Distribution
Contains no values far from the body of data

### Skewed Distribution
Has one tail much fatter or longer than the other
- A distribution is skewed *left* if the left tail is longer.

## Plots
### Stem and Leaf
- Used to show the frequency and spread of classes of data.
- Useful for small data sets
- Shows the range of the data
- Shows the shape of the data

```r
stem(c(1,2,3,4,4,5,8,12,14,21,22,24))

0 | 1 2 3 4 4
0 | 5 8
1 | 2 4
1 |
2 | 1 2 4
```

## Standard Deviation
Measure of how spread out the numbers are.
The average distance from the mean

![Standard Deviation](http://onlinestatbook.com/2/summarizing_distributions/graphics/pop_var.gif)

```haskell
s xs = sqrt $ 1/(n-1) * sum (x - μ)^2


s = sqrt . variance
```

Explanation:

`x - μ` - find the difference from the mean for each value  
`(x - μ) ^ 2` - Makes all numbers positive  
`1 / (n-1) * sum ` -  find the mean  
`sqrt ...` - convert units back to non-squared form

## Pearson's Correlation
Compute the Correlation Coefficient of two sets of data.

![Pearson's Correlation](http://onlinestatbook.com/2/describing_bivariate_data/graphics/pearson_formula.gif)

- `X`, `Y` - data sets
- `x`, `y` - mean of `{xᵢ - x̄ }` and `{yᵢ - ȳ }` respectively.


## Correlation vs Causality
[All the information you will ever need](http://www.tylervigen.com)

# Goodness of fit tests
## Kolmogorov-Smirnov test
Used to decide if a sample comes from a population with a specific distribution.

### iid - Independantly and Identically Distributed
- Value independant of the previous value
- Same probability of any other value in the distribution

### Empirical Distribution Function
Cumulative distribution function associated with the empirical measure of the
sample.

`(number of elements in sample < x) / n`

### Implemenation
```haskell
kolmogrovSmirnov :: (Num c, Ord c) => (a -> b -> c) -> a -> [b] -> [b] -> c
kolmogrovSmirnov f n xs ys = maximum . map abs $ zipWith (-) (f n xs) (f n ys)


f n xs = length [x | x <- xs, x <= n] / (length xs)
```

## [Anova](http://onlinestatbook.com/2/analysis_of_variance/intro.html)
Analysis Of Variance - between up to `n` sets.
- Used to test differences between two or more means.
- t-test is a form of Anova

## Residuals
The difference between the observed value of the dependent variable (y) and the
predicted value (ŷ) is called the residual (ε).

`ε = y - ŷ`

## Linear Regression
Linear regression consists of finding the best-fitting straight line through
the points. The best-fitting line is called a *regression line*.

Tests if there is a correlation between the data sets.

![Regression Line](http://onlinestatbook.com/2/regression/graphics/reg_error.gif)

![Regression Formula](http://www.microbiologybytes.com/maths/graphics/regression.gif.pagespeed.ce.AX7jJB4SGq.gif)

```r
b0 = Y - b1 * X

b1 = sum (x - x̄ )(y - ȳ) / sum ((xᵢ - x̄)^2)

yᵢ = b0 + b1*xᵢ + εᵢ
```

## Cook's Distance
Cook's distance is a statistic which tries to identify those values which have
more influence than others on the estimated coefficients. High peaks in the bar
chart might represent values that should be investigated further, since they
have a larger effect on the coefficients.


Combines the Residual the Leverage into one.

![Cook's Distance](https://docs.tibco.com/pub/spotfire/5.5.0-march-2013/UsersGuide/images/prd_cooks_distance.png)

## Binomial Distribution
Used to count the number of successes in Bernoulli Trials
```r
(n `chose` k) p^k (1 - p)^(n-k)
```
`(n chose r)` = Number of ways `k` objects can be chose from `n` distinct groups

#### Mean and Standard deviation of a Binomial Distribution
`μ = np`  
`σ = √(np(1-p))`


## Chi-Squared Test
Statistical test applied to sets of categorical data to evaluate how likely it
is that any observed difference between the sets arose by chance.

![Chi-Squared](http://www.biologycorner.com/resources/chi_square.gif)

## Chi-Squared Distribution
- Bounded on one side
- Tails off on one side
- Example: Average salary
![Chi-Squared Example](http://2012books.lardbucket.org/books/beginning-statistics/section_15/34d06306c2e726f6d5cd7479d9736e5e.jpg)

## Law of Large Numbers. (Normal)
When the sample X1 .. Xn is drawn from Normal (μ, σ) `X̄ = Normal (μ, σ/√n)`
- Centre stays the same.
- As n grows, spread decreases
- Greater probability that the value of X̄ is close to the mean.

## Central Unit Thorem (Not Normal)
When parent population is not normal use CLT
X̄ is asymptotically.  
i.e. for n large enough X̄ is Normal (μ, σ/√n)


*asymptotically* - a straight line that continually approaches a given curve but does not meet it at any finite distance.

##### Explain why the CLT can be used to justify the prevalence of the normal distributions in nature.


## R-squared
- Can be used to measure how well the the model fits the data.
- Gives the proportion of the total Response variable explained by Linear Regression Line
- When R^2 tends towards 1, linear regression is good


## Adjusted R^2
divides the sum of squares by their degrees of freedom
- Penalises models that get their 
