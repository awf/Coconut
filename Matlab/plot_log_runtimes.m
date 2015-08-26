function plot_log_runtimes( params, tools, times, title_, ylabel_,...
    do_plot_linear_quadratic_complexity)

% set(groot,'defaultAxesColorOrder',...
%     [.8 .1 0;0 .7 0;.2 .2 1; 0 0 0; .8 .8 0],...
%     'defaultAxesLineStyleOrder', '-|s-|x-|^-')
% 
% % ordering
% [tmp,preorder]=sort(times_J,2);
% preorder(isinf(tmp)) = NaN;
% scores=zeros(ntools,1);
% mask=~isnan(preorder);
% tmp=repmat(fliplr((1:ntools)),ntasks,1);
% scores(preorder(mask)) = scores(preorder(mask)) + tmp(mask);
% [~, order] = sort(scores);

lw = 2;
msz = 7;
x=[params{:}]; x=x(3:3:end);

figure; hold on;
for i=1:numel(tools)
    loglog(x, times(:, i),'linewidth',lw,'markersize',msz,...
        'color',tools(i).col,'marker',tools(i).marker);
end

% if do_plot_linear_quadratic_complexity
%     a = [min(x) max(x)];
%     plot(a,a/10000,'color',[.7 .7 .7])
%     plot(a,a.^2/50000,'color',[.7 .7 .7])
% end

legend(tools.name, 'location', 'nw');
set(gca,'FontSize',14,'xscale','log','yscale','log')
xlim([min(x) max(x)])
title(title_)
xlabel('# parameters')
ylabel(ylabel_)

end
